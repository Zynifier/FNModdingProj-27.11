// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Storm.generated.h"

class AFortGameModeAthena;
class UBehaviorTreeComponent;
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic;
enum class EFortSafeZoneState : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Storm : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnSafezoneStateChanged(const EFortSafeZoneState NewState);

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StormDestinationName;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CacheAthenaGameMode;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBehaviorTreeComponent> CachedBTComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_BattleRoyaleGamePhaseLogic> CachedGamePhaseLogic;

};

