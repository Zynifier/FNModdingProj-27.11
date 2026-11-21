// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/IGM/AthenaIGMPartyMemberWidget.h"
#include "AthenaIGMSquadMemberWidget.generated.h"

class AFortPlayerStateAthena;
class UFortLazyImage;
class UImage;
class UTextBlock;
enum class EKeepPlayingTogetherVotingStatus : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaIGMSquadMemberWidget : public UAthenaIGMPartyMemberWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandlePreserveSquadChanged(const bool bPreserveSquad);

	UFUNCTION(BlueprintImplementableEvent)
	void OnKeepPlayingTogetherVotingStatusChanged(const EKeepPlayingTogetherVotingStatus NewStatus, const bool bWasOptedIn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStarted(const bool bWasOptedIn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupAsFillSlot();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMSquadMemberWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_SquadMemberPortrait;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMSquadMemberWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_SquadMemberName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaIGMSquadMemberWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_PartyMemberIndicator;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> CachedSquadMember;

};

