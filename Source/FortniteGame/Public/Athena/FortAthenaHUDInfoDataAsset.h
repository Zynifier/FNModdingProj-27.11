// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "FortTeamEnum.h"
#include "FortAthenaHUDInfoDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FFortAthenaTeamHUDInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaTeamHUDInfo")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaTeamHUDInfo")
	FLinearColor Color;

};

UCLASS(MinimalAPI)
class UFortAthenaHUDInfoDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void FindTeamInfoForTeam(uint8 Team, UPARAM(DisplayName="Was Info Found") bool& bOutWasInfoFound, UPARAM(DisplayName="Team Info") FFortAthenaTeamHUDInfo& OutTeamInfo) const;

	UFUNCTION(BlueprintPure)
	void FindTeamInfoForTeamAffiliation(EFortTeamAffiliation::Type TeamAffiliation, UPARAM(DisplayName="Was Info Found") bool& bOutWasInfoFound, UPARAM(DisplayName="Team Info") FFortAthenaTeamHUDInfo& OutTeamInfo) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaHUDInfoDataAsset")
	TMap<uint8, FFortAthenaTeamHUDInfo> TeamInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaHUDInfoDataAsset")
	TMap<TEnumAsByte<EFortTeamAffiliation::Type>, FFortAthenaTeamHUDInfo> TeamAffiliationInfo;

};

