// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CreativeKnobBlueprintLibrary.generated.h"

class UFortPlaylistAthena;
class UObject;

UCLASS()
class UCreativeKnobBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Knobs|Class")
	static int32 GetAllTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedAnyTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedFirstTeamTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedFriendliesTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedHostilesTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedNeutralTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedNoneTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedSpawnOnNextRoundTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedSpawnTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetShiftedSpectateTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static TArray<int32> GetTeamArray(const UObject* InWorldContext, const UFortPlaylistAthena* InPlaylist = nullptr);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetTeamValue(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetTeamValueAsIndex(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 GetUnshiftedNeutralTeamValue();

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsActivatingTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Class")
	static bool IsClassAll(const int32 InClassValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Class")
	static bool IsClassAny(int32 InClassValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Class")
	static bool IsClassNone(int32 InClassValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsCompletingTeamWins(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsCooperativeTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsCustomTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsFreeForAllTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsSpawnOnNextRoundTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsSpawnTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsSpectateTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsSpectatingTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamAll(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamAllies(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamAny(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamDoNotSwitch(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamEnemies(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamFriendlies(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamHostiles(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamNeutral(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamNone(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamRandom(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamTriggeringPlayer(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTeamUseGameWinConditions(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsTriggeringTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsValidTeamIndex(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static bool IsWinningTeam(int32 InTeamValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 ReshiftTeamIndexValue(int32 InValue);

	UFUNCTION(BlueprintPure, Category="Knobs|Team")
	static int32 ReshiftTeamValue(int32 InValue);

};

