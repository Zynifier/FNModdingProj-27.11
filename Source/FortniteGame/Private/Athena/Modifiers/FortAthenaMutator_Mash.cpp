// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Mash.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaMutator_Mash::ArePlayerScoresFinal() const
{
	return false;
}

void AFortAthenaMutator_Mash::BuildAndReportPlayersScores_PostMatch() const
{
}

const FText& AFortAthenaMutator_Mash::GetBossDisplayName() const
{
	static FText Dummy;
	return Dummy;
}

const FMashBossHealthShieldData& AFortAthenaMutator_Mash::GetBossHealthShieldData() const
{
	static FMashBossHealthShieldData Dummy;
	return Dummy;
}

bool AFortAthenaMutator_Mash::GetPlayerBestScore(AFortPlayerControllerAthena* AthenaPC, int32& OutStatValue) const
{
	return false;
}

bool AFortAthenaMutator_Mash::GetPlayerScore(const AFortPlayerControllerAthena* AthenaPlayerController, int32& OutScore) const
{
	return false;
}

bool AFortAthenaMutator_Mash::GetPlayerScoreFromPlayerState(const AFortPlayerStateAthena* AthenaPlayerState, int32& OutScore) const
{
	return false;
}

float AFortAthenaMutator_Mash::GetStreakScoreMultiplierResetTime() const
{
	return float();
}

int32 AFortAthenaMutator_Mash::GetTeamScore(const uint8 TeamId) const
{
	return int32();
}

void AFortAthenaMutator_Mash::HandleAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaMutator_Mash::HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy)
{
}

void AFortAthenaMutator_Mash::HandleAISpecialEncounterAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy)
{
}

void AFortAthenaMutator_Mash::HandleBossAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaMutator_Mash::HandleBossPawnHealthShieldChanged()
{
}

void AFortAthenaMutator_Mash::HandleRiftDamaged(AActor* DamagedRiftActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaMutator_Mash::HandleRiftDying(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift, AController* Controller, AActor* DamageActor)
{
}

void AFortAthenaMutator_Mash::HandleRiftSpawned(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift)
{
}

void AFortAthenaMutator_Mash::MaybeSpawnAISpecialEncounterForSafeZone(const int32 InSafeZoneIndex)
{
}

void AFortAthenaMutator_Mash::OnRep_BossHealthShieldData()
{
}

void AFortAthenaMutator_Mash::OnRep_BossPawn()
{
}

void AFortAthenaMutator_Mash::OnRep_bScoresAreFinal()
{
}

void AFortAthenaMutator_Mash::OnRep_CurrentPhase()
{
}

void AFortAthenaMutator_Mash::OnRep_PlayerData()
{
}

void AFortAthenaMutator_Mash::OnRep_TeamScoreMultiplier()
{
}

void AFortAthenaMutator_Mash::OnScoreMultiplierInteractionCompleted(ABuildingActor* SelfActor, AFortPawn* InteractingPawn)
{
}

void AFortAthenaMutator_Mash::ResetStreakScoreMultiplier(AFortPlayerStateAthena* PlayerState)
{
}

void AFortAthenaMutator_Mash::RetrievePlayerFriendsLeaderBoard(AFortPlayerControllerAthena* AthenaPC)
{
}

void AFortAthenaMutator_Mash::ScheduleMarkPlayerScoresAsFinal()
{
}

void AFortAthenaMutator_Mash::SpawnObjectiveAreaObjects()
{
}

void AFortAthenaMutator_Mash::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Mash, bIsRespawningAllowed);
	DOREPLIFETIME(AFortAthenaMutator_Mash, TotalObjectiveAreaCount);
	DOREPLIFETIME(AFortAthenaMutator_Mash, TeamScoreMultiplier);
	DOREPLIFETIME(AFortAthenaMutator_Mash, PlayerDataArray);
	DOREPLIFETIME(AFortAthenaMutator_Mash, bScoresAreFinal);
	DOREPLIFETIME(AFortAthenaMutator_Mash, CurrentPhase);
	DOREPLIFETIME(AFortAthenaMutator_Mash, BossPawn);
	DOREPLIFETIME(AFortAthenaMutator_Mash, bFinalBossEncounterSpawned);
	DOREPLIFETIME(AFortAthenaMutator_Mash, BossHealthShieldData);
}

void UFortCheatManager_Mash::MashFinalPhase(const FName BossEncounterName)
{
}

void UFortCheatManager_Mash::MashGetAISpecialEncounterNames()
{
}

void UFortCheatManager_Mash::MashSetFinalBoss(const FName BossEncounterName)
{
}

void UFortCheatManager_Mash::MashSetNextAISpecialEncounter(const FName EncounterName)
{
}

void UFortCheatManager_Mash::MashSpawnScoreMultiplier()
{
}

void UFortCheatManager_Mash::MashWin()
{
}
