// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "LobbyBeaconClient.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortGender.h"
#include "FortLobbyBeaconClient.generated.h"

class UFortHeroType;

UCLASS(Abstract)
class AFortLobbyBeaconClient : public ALobbyBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientCreateOrJoinChatRoom(const FString& ChatRoomId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTeamChatRoomReady(const FString& ChatRoomId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerToggleIsLobbyTimerPaused();

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerIncrementHomeBaseVersion(const FUniqueNetIdRepl& InUniqueId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetCharacterGender(const FUniqueNetIdRepl& InUniqueId, EFortCustomGender::Type GenderType);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetConsoleUniqueNetId(const FUniqueNetIdRepl& InUniqueId, const FUniqueNetIdRepl& NewConsoleNetId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetCosmeticLoadout(const FUniqueNetIdRepl& InUniqueId, const FFortAthenaLoadout& InLoadout);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetCurrentCharacterXp(const FUniqueNetIdRepl& InUniqueId, const int32 CurrentCharacterXp);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetGadget(const FUniqueNetIdRepl& InUniqueId, int32 Index, const FString& GadgetPersistentName);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetHeroId(const FUniqueNetIdRepl& InUniqueId, const FString& InHeroId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetHeroType(const FUniqueNetIdRepl& InUniqueId, const UFortHeroType* InHeroType);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetMatchmakingLevel(const FUniqueNetIdRepl& InUniqueId, const int32 MatchmakingLevel);

};

