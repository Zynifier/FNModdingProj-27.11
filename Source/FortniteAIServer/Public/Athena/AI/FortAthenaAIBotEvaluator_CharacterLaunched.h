// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_CharacterLaunched.generated.h"

class AFortPlayerPawn;
class UFortAthenaAIBotMovementDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_CharacterLaunched : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnZiplineStateChanged(bool bIsZiplining, AFortPlayerPawn* FortPlayerPawn);

	UPROPERTY(EditAnywhere, Category="EvasiveGameplay", meta=(AllowPrivateAccess="true"))
	bool bSteerInSameDirectionAsLaunchVelocity;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CharacterLaunchedExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SteerDirectionKeyName;

	UPROPERTY(Transient)
	FVector LastLaunchVelocity;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CachedMovementSkillSet;

};

