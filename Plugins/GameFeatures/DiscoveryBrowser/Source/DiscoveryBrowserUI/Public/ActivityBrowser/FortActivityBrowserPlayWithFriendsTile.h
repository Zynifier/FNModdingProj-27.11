// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ActivityBrowser/FortActivityBrowserTileBase.h"
#include "FortActivityBrowserPlayWithFriendsTile.generated.h"

class UFortGameActivity;
class UFortJoinablePartyPortraitsDisplay;
class USocialUser;
class UTexture;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivityBrowserPlayWithFriendsTile : public UFortActivityBrowserTileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FText GetCTAButtonText();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Party Information Updated"))
	void BP_PartyInformationUpdated(bool bInIsTileSelected);

	UFUNCTION(BlueprintPure)
	const int32 GetMaxPartySize() const;

	UFUNCTION(BlueprintCallable)
	void HandleCTAButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTextureBeginLoading();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTextureLoadingComplete(const UTexture* ThumbnailTexture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTileActiveChanged(const bool bIsTileActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateColumnSize(int32 NewColumnSize);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCTAButtonInfo(const FText& InteractionText, const bool bInteractionFound);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCTAButtonInteraction(const bool bIsInteractionEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateIslandThumbnail(const UTexture* ThumbnailTexture);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLastInteraction(const FText& LastInteraction);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateOtherPlayersSubText(const FText& OtherPlayersSubText);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePartyMemberNames(const FText& Names);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRichPresence(const FText& RichPresence);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSingleFriendName(const FText& SingleFriendName);

	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Max amount of players' names to display in a tile."))
	int32 MaxNamesToDisplay;

	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Max amount of players' portraits to display in a tile."))
	int32 MaxPortraitsToDisplay;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserPlayWithFriendsTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortJoinablePartyPortraitsDisplay> PartyMembersAvatarsDisplay;

	UPROPERTY(BlueprintReadOnly, Category="FortActivityBrowserPlayWithFriendsTile", meta=(AllowPrivateAccess, BindWidget))
	bool bIsActiveInvite;

	UPROPERTY(BlueprintReadOnly, Category="FortActivityBrowserPlayWithFriendsTile", meta=(AllowPrivateAccess, BindWidget))
	int32 CurrentPartySize;

	UPROPERTY(BlueprintReadOnly, Category="FortActivityBrowserPlayWithFriendsTile", meta=(AllowPrivateAccess, BindWidget))
	bool bIsPartyPrivate;

	UPROPERTY(Transient)
	UFortGameActivity* CachedGameActivity;

	UPROPERTY(Transient)
	TWeakObjectPtr<USocialUser> CachedTargetSocialUser;

	UPROPERTY(Transient)
	FText CurrentCTAButtonText;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowserPlayWithFriendsTile")
	FText JoinPartyText;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowserPlayWithFriendsTile")
	FText RequestToJoinText;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserPlayWithFriendsTile")
	FDataTableRowHandle JoinFriendInputAction_Touch;

};

