
const names = document.getElementById("names")
const num = document.getElementById("num")
const chinhHopRes = document.getElementById("chinhHop")
const toHopRes = document.getElementById("toHop")



const show = (a, n, parent) => {
	
    let s = ""

    for (let i = 0; i < n; i++) {
        const e = a[i];
        s = `${s} ${e}`
    }

    const node = document.createElement("li");
    const textnode = document.createTextNode(s);
    node.appendChild(textnode);

    parent.appendChild(node)
}

const toHop = (index, start, a, n, arr) => {
	if (index >= n) {
		show(a, n, toHopRes);
		return;
	}

	for (let i = start; i < n; i++) {
		a[index] = arr[i];
		toHop(index + 1, i, a, n, arr);
	}
}

const chinhHop = (index, a, n, arr) => {
	if (index >= n) {
		show(a, n, chinhHopRes);
		return;
	}

	for (let i = 0; i < n; i++) {
		a[index] = arr[i];
		chinhHop(index + 1, a, n, arr);
	}
}


const calc = () => {
   
    const arr = names.value.split(" ")
    const n = parseInt(num.value) 
    let a = []
    for (let i = 0; i < arr.length; i++) {
        a.push(0)
    }
    toHop(0, 0, a, n, arr)
    chinhHop(0, a, n, arr)
}
