// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortPathFollowingComponentBase.h"
#include "FortAthenaAIBotPathFollowingComponent.generated.h"

class ABuildingActor;
class AFortAthenaAIBotController;
class AFortPawn;
class UFortAthenaAIBotMovementDigestedSkillSet;
class UFortAthenaAIBotUnstuckDigestedSkillSet;
class UFortAthenaAIBotVehicleDigestedSkillSet;

UCLASS(BlueprintType)
class FORTNITEAI_API UFortAthenaAIBotPathFollowingComponent : public UFortPathFollowingComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandlePawnTeleported(AFortPawn* TeleportedPawn);

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> BotController;

private:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> HitBuilding;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotUnstuckDigestedSkillSet> CachedUnstuckSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CachedMovementSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotVehicleDigestedSkillSet> CachedVehicleSkillSet;

};

