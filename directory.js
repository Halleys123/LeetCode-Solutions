// Sample command
//node .\directory.js PROBLEM=1528 SOLUTIONS=5 LANGUAGES=.py,.cpp REMOVE=true REFACTOR=true
//node .\directory.js PROBLEM=1979 SOLUTIONS=2 LANGUAGES=.cpp

const path = require('path');
const fs = require('fs');
const count = require('number-to-words');
const axios = require('axios');
const cheerio = require('cheerio');

const languages = [
  {
    name: 'Python',
    extension: '.py',
  },
  {
    name: 'CPP',
    extension: '.cpp',
  },
  {
    name: 'JavaScript',
    extension: '.js',
  },
  {
    name: 'Java',
    extension: '.java',
  },
  {
    name: 'C',
    extension: '.c',
  },
  {
    name: 'SQL',
    extension: '.sql',
  },
];

let error = false;
// read arguments from the command line
const args = process.argv.slice(2);
// [ 'PROBLEM=0034', 'SOLUTIONS=5', 'Extensions=.py,.cpp' ]
// create folder with problem number
// create files with the given languages with the given extensions

let problem = args[0].split('=')[1];
const solutions = args[1].split('=')[1];
const extensions = args[2].split('=')[1].split(',');
const remove = args[3] ? args[3].split('=')[1] : false;
const refactor = args[4] ? args[4].split('=')[1] === 'true' : false;

if (refactor) {
  if (!fs.existsSync(folderPath)) {
    console.log(
      'Problem folder does not exist. Continuing the process like normal.'
    );
  } else {
    const files = fs.readdirSync(folderPath);
    const programmingFiles = files.filter((file) =>
      validExtensions.includes(path.extname(file))
    );
    const subFolders = files.filter((file) =>
      fs.lstatSync(path.join(folderPath, file)).isDirectory()
    );

    if (programmingFiles.length > 0 && subFolders.length === 0) {
      const fileExtension = path.extname(programmingFiles[0]);
      const language = languages.find(
        (lang) => lang.extension === fileExtension
      );
      const langFolder = path.join(folderPath, language.name);
      if (!fs.existsSync(langFolder)) {
        fs.mkdirSync(langFolder);
      }
      programmingFiles.forEach((file) => {
        const oldPath = path.join(folderPath, file);
        const newPath = path.join(langFolder, file);
        fs.renameSync(oldPath, newPath);
      });
    } else if (subFolders.length > 0) {
      extensions.forEach((extension) => {
        const language = languages.find((lang) => lang.extension === extension);
        const langFolder = path.join(folderPath, language.name);
        if (!fs.existsSync(langFolder)) {
          fs.mkdirSync(langFolder);
        }
        for (let i = 1; i <= solutions; i++) {
          const fileName = `${returnNum(i)}${extension}`;
          const filePath = path.join(langFolder, fileName);
          fs.writeFileSync(filePath, '');
        }
      });
    }
  }
  process.exit(0);
}

// if problem is a number of not length 4
if (problem.length !== 4 && !isNaN(problem)) {
  problem = problem.padStart(4, '0');
}
if (!/^[0-9]{4}$/.test(problem)) {
  console.log('Invalid problem number');
  error = true;
  return;
}

// check validty of solutions
if (!/^[0-9]+$/.test(solutions)) {
  console.log('Invalid number of solutions');
  error = true;
  return;
}

// check validty of extensions
const validExtensions = languages.map((lang) => lang.extension);
for (let extension of extensions) {
  if (!validExtensions.includes(extension)) {
    console.log('Invalid extension');
    error = true;
    return;
  }
}

// create folder
const folderName = `${problem}`;
const folderPath = path.join(__dirname, folderName);
if (!fs.existsSync(folderPath)) {
  fs.mkdirSync(folderPath);
} else {
  if (remove) {
    fs.rmdirSync(folderPath, { recursive: true });
    fs.mkdirSync(folderPath);
  } else {
    console.log('Folder already exists');
    error = true;
    return;
  }
}
// if only one language is given, create files with that language directly in problem folder
// else create a folder for each language and create files in that folder
function returnNum(i) {
  return count
    .toWords(i)
    .split(' ')
    .map((item) => item.charAt(0).toUpperCase() + item.slice(1))
    .join('');
}
try {
  if (extensions.length === 1) {
    for (let i = 1; i <= solutions; i++) {
      const fileName = `${returnNum(i)}${extensions[0]}`;
      const filePath = path.join(folderPath, fileName);
      fs.writeFileSync(filePath, '');
    }
  } else {
    for (let lang of languages) {
      if (extensions.includes(lang.extension)) {
        const langFolder = path.join(folderPath, lang.name);
        if (!fs.existsSync(langFolder)) {
          fs.mkdirSync(langFolder);
        }
        for (let i = 1; i <= solutions; i++) {
          // to camel
          const fileName = `${returnNum(i)}${lang.extension}`;
          const filePath = path.join(langFolder, fileName);
          fs.writeFileSync(filePath, '');
        }
      }
    }
  }
} catch (err) {
  console.log(err);
  fs.rmdirSync(folderPath, { recursive: true });
  return;
}

async function fetchProblemStatement(problemNumber) {
  try {
    const searchUrl = `https://www.google.com/search?q=leetcode+${problemNumber}`;
    const { data } = await axios.get(searchUrl, {
      headers: {
        'User-Agent':
          'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
      },
    });
    const $ = cheerio.load(data);
    const firstLink = $('a')
      .filter((i, el) => $(el).attr('href').includes('leetcode.com/problems'))
      .first()
      .attr('href');
    if (!firstLink) throw new Error('Problem link not found');

    const problemUrl = firstLink.startsWith('http')
      ? firstLink
      : `https://www.google.com${firstLink}`;
    const { data: problemData } = await axios.get(problemUrl, {
      headers: {
        'User-Agent':
          'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
      },
    });
    const $$ = cheerio.load(problemData);
    const problemStatement = $$("[data-track-load='description-content']")
      .text()
      .trim();
    if (!problemStatement) throw new Error('Problem statement not found');

    return problemStatement;
  } catch (error) {
    return null;
  }
}

(async () => {
  const readmePath = path.join(folderPath, 'README.md');
  const problemStatement = await fetchProblemStatement(problem);
  if (problemStatement) {
    fs.writeFileSync(readmePath, problemStatement);
  } else {
    fs.writeFileSync(readmePath, 'Problem statement not found.');
  }
  console.log('Folder created successfully');
})();
