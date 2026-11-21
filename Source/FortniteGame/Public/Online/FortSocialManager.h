// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialManager.h"
#include "Online/FortMcpProfileCommonCore.h"
#include "FortSocialManager.generated.h"

class UFortLocalTeam;
class UFortPartyMember;
class UFortSocialUser;

UENUM()
enum class EJoinPartySource : uint8
{
	Sidebar = 0,
	Toast = 1,
	Lobby = 2,
	Discovery = 3,
	RequestToJoin = 4,
	RichPresence = 5,
	RiftPortal = 6,
	CommandLine = 7,
	MAX_NUM = 8,
};

UCLASS(MinimalAPI)
class UFortSocialManager : public USocialManager
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	ESocialImportPanelPlatform SocialImportPlatform;

	UPROPERTY()
	bool bTutorialCompleted;

	UPROPERTY()
	bool bLeftLastPartyFromGameDisconnect;

	UPROPERTY()
	TObjectPtr<UFortLocalTeam> LocalTeam;

	UPROPERTY(Config)
	double NoPersistentPartyDetectorTimeout;

	UPROPERTY(Config)
	bool bEnablePartyJoinReturnToMainMenu;

	UPROPERTY(Config)
	double PendingQueryPartyJoinabilityResultTimeout;

	UPROPERTY(Transient)
	TObjectPtr<UFortSocialUser> CurrentJoinAndSpectateTarget;

	UPROPERTY(Transient)
	TObjectPtr<UFortPartyMember> PartyMemberToSpectate;

	UPROPERTY(Config)
	bool bEnablePartyAnalytics;

};

