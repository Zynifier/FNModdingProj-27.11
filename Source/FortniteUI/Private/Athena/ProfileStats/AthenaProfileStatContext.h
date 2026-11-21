// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "AthenaPlayerMatchReport.h"
#include "BlueprintContextBase.h"
#include "AthenaProfileStatContext.generated.h"

class UAthenaMatchSetStatView;
class UAthenaMatchStatView;
class UAthenaSeasonStats;
class UAthenaWeaponStatView;
class UFortMcpProfileAthenaStats;
class UFortWeaponItemDefinition;

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UAthenaBaseStatView : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaBaseStatView")
	float GetStat(const FGameplayTag& InStat) const;

};

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UAthenaMatchStatView : public UAthenaBaseStatView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	const FDateTime GetMatchEndTime() const;

	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	FString GetMatchID() const;

	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	TArray<UAthenaWeaponStatView*> GetSortedWeaponViews(const FGameplayTag& InStat) const;

	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	UAthenaWeaponStatView* GetWeaponViewHighestStat(const FGameplayTag& InStat) const;

	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	TArray<UAthenaWeaponStatView*> GetWeaponViews() const;

private:
	UPROPERTY()
	TArray<TObjectPtr<UAthenaWeaponStatView>> WeaponStatViews;

};

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UAthenaMatchSetStatView : public UAthenaMatchStatView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaMatchStatView")
	TArray<UAthenaMatchStatView*> GetBestMatchViews() const;

	UFUNCTION(BlueprintCallable, Category="AthenaMatchStatView")
	UAthenaSeasonStats* GetOwningSeason();

private:
	UPROPERTY()
	TObjectPtr<UAthenaSeasonStats> OwningSeason;

	UPROPERTY()
	FName PlaylistID;

	UPROPERTY()
	TArray<TObjectPtr<UAthenaMatchStatView>> BestMatches;

};

UCLASS()
class FORTNITEUI_API UAthenaProfileStatContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAthenaStatsProfileLoaded, UFortMcpProfileAthenaStats*, StatProfile);

public:
	UFUNCTION(BlueprintCallable)
	UAthenaMatchStatView* CreateCurrentMatchStatView();

	UFUNCTION(BlueprintCallable)
	UAthenaMatchSetStatView* CreateMatchStatView(UAthenaSeasonStats* StatSet, FName Bucket);

	UFUNCTION(BlueprintCallable)
	TArray<UAthenaMatchStatView*> CreateMatchViews(const TArray<FAthenaMatchStats>& InRecentMatches);

	UPROPERTY()
	FOnAthenaStatsProfileLoaded OnStatsProfileLoaded;

};

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UAthenaWeaponStatView : public UAthenaBaseStatView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaWeaponStatView")
	UFortWeaponItemDefinition* GetWeaponDefinition() const;

};

