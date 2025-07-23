/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(!digits) return [];
    const phoneMap={
        "2":"abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    };
//     const result=[];

//     function backtrack(index,path){
//         if(path.length===digits.length){
//             result.push(path);
//             return;
//         }

//         const possibleLetters=phoneMap[digits[index]];

//         for(let letter of possibleLetters){
//             backtrack(index+1,path+letter);
//         }
//     }
//     backtrack(0,"");
//     return result;
    
    
    const result=[];
    
    function backtrack(index,path){
        if(path.length===digits.length){
            result.push(path);
            return;
        }
        
        const possibleLetters=phoneMap[digits[index]];
        
        for(letter of possibleLetters){
            backtrack(index+1,path+letter);
        }
    }
    backtrack(0,"");
    return result;
};