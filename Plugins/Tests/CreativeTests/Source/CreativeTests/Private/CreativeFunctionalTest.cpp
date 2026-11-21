// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeFunctionalTest.h"
#include "Net/UnrealNetwork.h"

bool ACreativeFunctionalTest::CheckIfAllConditionsSatisifed() const
{
	return false;
}

bool ACreativeFunctionalTest::GetCreatedDevices(TArray<AActor*>& OutCreatedDevices)
{
	return false;
}

bool ACreativeFunctionalTest::GetCreatedDevicesOfClass(TSubclassOf<AActor> DeviceClass, TArray<AActor*>& OutCreatedDevices)
{
	return false;
}

APlayerController* ACreativeFunctionalTest::GetPlayerControllerForTest() const
{
	return nullptr;
}

void ACreativeFunctionalTest::HandleConditionSatisfiedChange_Implementation(UCreativeFunctionalTestConditionComponentBase* Condition)
{
}

void ACreativeFunctionalTest::OnLevelRecordFinishSpawning(const TArray<AActor*>& NewlySpawnedActors)
{
}

void ACreativeFunctionalTest::OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState)
{
}

void ACreativeFunctionalTest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACreativeFunctionalTest, CreatedDevices);
}
