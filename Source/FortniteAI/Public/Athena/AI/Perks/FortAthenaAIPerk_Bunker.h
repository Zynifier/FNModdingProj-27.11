// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "AI/Perks/FortAIPerkBase.h"
#include "FortAthenaAIPerk_Bunker.generated.h"

USTRUCT()
struct FFortAIRuntimePerkInfo_Bunker : public FFortAIRuntimePerkInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float OddsToBeUsedAgainstUnknownThreat;

	UPROPERTY(Transient)
	float OddsToUseRoofBuilding;

	UPROPERTY(Transient)
	float OddsToBuildForwardRamp;

	UPROPERTY(Transient)
	float InitialBuildDelay;

	UPROPERTY(Transient)
	float SamePieceBuildDelay;

	UPROPERTY(Transient)
	float SamePieceBuildDelayRandomDeviation;

	UPROPERTY(Transient)
	float DifferentPieceBuildDelay;

	UPROPERTY(Transient)
	float DifferentPieceBuildDelayRandomDeviation;

	UPROPERTY(Transient)
	float OddsToSelectRandomMaterial;

};

UCLASS(MinimalAPI)
class UFortAthenaAIPerk_Bunker : public UFortAIPerkBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToBeUsedAgainstUnknownThreat;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToUseRoofBuilding;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToBuildForwardRamp;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat InitialBuildDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat SamePieceBuildDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat SamePieceBuildDelayRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat DifferentPieceBuildDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat DifferentPieceBuildDelayRandomDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_Bunker", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToSelectRandomMaterial;

};

