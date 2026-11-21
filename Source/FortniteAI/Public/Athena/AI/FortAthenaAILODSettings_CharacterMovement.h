// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAILODSettingsInterfaces.h"
#include "FortAthenaAILODSettings_CharacterMovement.generated.h"

class UFortMovementComp_Character;

USTRUCT(BlueprintType)
struct FFortAILODSetting_CharacterMovement : public FFortAthenaAILODSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat Interval;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat RandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat MinimumDynamicInterval;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat MaximumDotDifferenceBetweenInputVectors;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat bDisableAvoidance;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat bBotsEnableNavWalkingMode;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat bBotsEnablePhysNavWalkingPathFollowingMode;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat bSweepWhileNavWalking;

	UPROPERTY(EditDefaultsOnly, Category="AILOD", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat bGenerateOverlapInNavWalking;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAILODSettings_CharacterMovement : public UObject, public IFortAthenaAILODSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortMovementComp_Character>> SystemClasses;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement BelowLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement LowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement AboveLowerLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement BelowNormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement NormalLODSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FFortAILODSetting_CharacterMovement AboveNormalLODSettings;

};

