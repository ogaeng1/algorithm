function solution(strArr) {
    const answer = {};

    for (let i = 0; i < strArr.length; i++) {
        const len = strArr[i].length;
        answer[len] = (answer[len] || 0) + 1;
    }

    return Math.max(...Object.values(answer));
}
