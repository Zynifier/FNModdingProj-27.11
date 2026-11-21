// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PapayaServerMigrationComponent.generated.h"

class AGameStateBase;

USTRUCT(BlueprintType)
struct FServerMigrationAlertData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ServerMigrationAlertData")
	int32 SecondsRemainingStart;

	UPROPERTY(EditDefaultsOnly, Category="ServerMigrationAlertData")
	int32 SecondsRemainingEnd;

	UPROPERTY(Transient)
	FTimerHandle TimerHandle;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UPapayaServerMigrationComponent : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnGameStateReady(AGameStateBase* GameState);

	UFUNCTION()
	void OnRep_LastRequestedTimeForMigrationTimerPushback();

private:
	UPROPERTY(EditDefaultsOnly, Category="PapayaServerMigrationComponent")
	TArray<FServerMigrationAlertData> AlertDataList;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LastRequestedTimeForMigrationTimerPushback)
	float LastRequestedTimeForMigrationTimerPushback;

};

