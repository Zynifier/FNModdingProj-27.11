// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "LobbyBeaconPlayerState.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortGender.h"
#include "Player/FortPlayerState.h"
#include "FortLobbyBeaconPlayerState.generated.h"

class UFortHeroType;

UCLASS(Abstract, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLobbyBeaconPlayerState : public ALobbyBeaconPlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing=OnRep_ConsoleUniqueNetId)
	FUniqueNetIdRepl ConsoleUniqueNetId;

	UPROPERTY(Replicated)
	FString Platform;

	UPROPERTY(Replicated)
	uint8 TeamAffiliation;

	UPROPERTY(ReplicatedUsing=OnRep_CharXP)
	int32 CurrentCharXP;

	UPROPERTY(Replicated)
	int32 MatchmakingLevel;

	UPROPERTY(ReplicatedUsing=OnRep_HeroId)
	FString HeroId;

	UPROPERTY(ReplicatedUsing=OnRep_HeroType)
	TObjectPtr<UFortHeroType> HeroType;

	UPROPERTY(ReplicatedUsing=OnRep_CosmeticLoadout)
	FFortAthenaLoadout CosmeticLoadout;

	UPROPERTY(ReplicatedUsing=OnRep_LobbyTimeRemaining)
	int32 LobbyTimeRemaining;

	UPROPERTY(ReplicatedUsing=OnRep_HomeBaseVersion)
	int64 HomeBaseVersion;

	UPROPERTY(ReplicatedUsing=OnRep_Gadgets)
	TArray<FString> SelectedGadgets;

protected:
	UFUNCTION()
	void OnRep_CharacterGender();

	UFUNCTION()
	void OnRep_CharXP();

	UFUNCTION()
	void OnRep_ConsoleUniqueNetId();

	UFUNCTION()
	void OnRep_CosmeticLoadout();

	UFUNCTION()
	void OnRep_Gadgets();

	UFUNCTION()
	void OnRep_HeroId();

	UFUNCTION()
	void OnRep_HeroType();

	UFUNCTION()
	void OnRep_HomeBaseVersion();

	UFUNCTION()
	virtual void OnRep_LobbyTimeRemaining();

	UPROPERTY()
	ETrustedPlatformType TrustedPlatformType;

	UPROPERTY(ReplicatedUsing=OnRep_CharacterGender)
	TEnumAsByte<EFortCustomGender::Type> CharacterGender;

};

