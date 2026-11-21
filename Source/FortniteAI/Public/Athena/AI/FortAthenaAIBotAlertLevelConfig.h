// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaAIBotAlertLevelConfig.generated.h"

class UAISenseScalableConfig;

UCLASS(Abstract, EditInlineNew)
class UAISenseScalableConfig : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UAISenseScalableConfig_Hearing : public UAISenseScalableConfig
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sense")
	FScalableFloat HearingRange;

};

UCLASS()
class UAISenseScalableConfig_Sight : public UAISenseScalableConfig
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Sight", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat SightRadius;

	UPROPERTY(EditDefaultsOnly, Category="Sight", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	FScalableFloat LoseSightRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sight", meta=(ClampMax="180.000000", ClampMin="0.000000", DisplayName="PeripheralVisionHalfAngleDegrees", UIMax="180.000000", UIMin="0.000000"))
	FScalableFloat PeripheralVisionAngleDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sight", meta=(ClampMin="0.000000", DisplayName="PointOfViewBackwardOffset", UIMin="0.000000"))
	FScalableFloat PointOfViewBackwardOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sight", meta=(ClampMin="0.000000", DisplayName="NearClippingRadius", UIMin="0.000000"))
	FScalableFloat NearClippingRadius;

};

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortAthenaAIBotAlertLevelConfig : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AlertLevelConfig", meta=(Bitmask, BitmaskEnum="/Script/FortniteAI.EAlertLevel"))
	int32 AlertLevels;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="AlertLevelConfig")
	TObjectPtr<UAISenseScalableConfig> ScalableSenseConfig;

};

