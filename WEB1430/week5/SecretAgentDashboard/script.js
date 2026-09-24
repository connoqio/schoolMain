function initializeDashboard() {
  const container = document.getElementById("mission-container");
  container.innerHTML = `
    <h1>Secret Agent Dashboard</h1>
    <ul id="mission-list">
      <li data-id="0">Decode encrypted message</li>
      <li data-id="1">Gather intel</li>
      <li data-id="2">Disable security system</li>
    </ul>
  `;
}

function addMission(text){
  const missionList = document.getElementById("mission-list");
  const newMission = document.createElement("li");
  newMission.textContent = text;
  missionList.appendChild(newMission);
}

function updateMission(index, newText){
  const missionList = document.getElementById("mission-list");
  const targetMission = missionList.children[index];

  if (targetMission){
    targetMission.textcontent = newText;
  }
}

function deleteMission(index){
  missionList = document.getElementById("mission-list");
  const targetMission = missionList.children[index];

  if (targetMission) {
    targetMission.remove();
  }
}

function insertAfter(newText, referenceIndex){
  missionList = document.getElementById("mission-list");
  const referenceMission = missionList.children[referenceIndex];

  if (referenceMission) {
    const newMission = document.createElement("li");
    newMission.textContent = newText;

    referenceMission.insertAdjacentElement("afterend", newMission);
  }
}

initializeDashboard()
addMission("Extract high-value asset");
updateMission(1, "Gather satellite intel");
deleteMission(1);
insertAfter("Intercept communications", 0);