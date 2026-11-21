// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Engine/DataTable.h"
#include "Misc/DateTime.h"
#include "Types/SlateEnums.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "OnlineLinkId.h"
#include "OnlineLinkModerationStatus.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCreativeIslandLinkScreen.generated.h"

class AFortAthenaCreativePortal;
class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;
class UEditableText;
class UFortCreativeIslandLink;
class UListView;
class UObject;
class UScrollBox;
enum class EFortActivityValidationResult : uint8;

UENUM(BlueprintType)
enum class EFortCreativeIslandLinkCategory : uint8
{
	// Island in this list for unspecified reason

	Default = 0,
	// Island player has favorited

	Favorite = 1,
	// Island player has published

	Published = 2,
	// Island player has recently entered or visited

	Recent = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeIslandCodeConfirmed, const UFortCreativeIslandLink*, IslandLink);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEditableTextIslandLinkModified);

USTRUCT()
struct FCachedIslandsGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortCreativeIslandLink>> IslandLinks;

};

UCLASS(BlueprintType)
class UFortCreativeIslandLink : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FOnlineLinkId LinkId;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString CreatorUsername;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString SupportCode;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString Tagline;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	TArray<FString> DescriptionTags;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString Introduction;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString ImageUrl;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	EFortCreativeIslandLinkCategory Category;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	bool bDummyLink;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	int32 Matchmaking_MaximumNumberOfPlayers;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	FString Matchmaking_MMSType;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	int32 Matchmaking_PlayersPerTeam;

	UPROPERTY()
	FDateTime SortDate;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLink")
	EOnlineLinkModerationStatus ModerationStatus;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandLinkEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandLinkScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddIslandToFavorites(UFortCreativeIslandLink* LinkEntry);

	UFUNCTION(BlueprintPure)
	FOnlineLinkId GetLinkIdFromInput() const;

	UFUNCTION(BlueprintPure)
	FText GetTextFromLinkId(const FOnlineLinkId& LinkId) const;

	UFUNCTION(BlueprintCallable)
	void RemoveIslandFromFavorites(UFortCreativeIslandLink* LinkEntry);

	UFUNCTION(BlueprintCallable)
	void RemoveIslandFromHistory(const FOnlineLinkId& LinkCode);

	UFUNCTION(BlueprintCallable)
	void SetFavoritesOnlyMode(bool bFavoritesOnly);

	UFUNCTION(BlueprintCallable)
	void SetTargetPortal(AFortAthenaCreativePortal* Portal);

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandLinkScreen")
	int32 NumDebugIslandLinks;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeIslandCodeConfirmed OnCreativeIslandCodeConfirmed;

	UPROPERTY(BlueprintAssignable)
	FOnEditableTextIslandLinkModified OnEditableTextIslandLinkModified;

protected:
	UFUNCTION(BlueprintPure)
	FText GetMatchmakingTypeDescription(const UFortCreativeIslandLink* IslandLink) const;

	UFUNCTION(BlueprintPure)
	bool IsPartyEligible(const UFortCreativeIslandLink* IslandLink) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreativeIslandLinksPopulated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreativeIslandLinkValidated(EFortActivityValidationResult Error, bool IsValidModerationState);

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandLinkScreen")
	FText MatchmakingOffDescription;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandLinkScreen")
	FText MatchmakingKeepFullDescription;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandLinkScreen")
	FText MatchmakingRespectPartiesDescription;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandLinkScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_IslandLink;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeIslandLinkScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> ListView_IslandLinks;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandLinkScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Details;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLinkScreen")
	TObjectPtr<UFortCreativeIslandLink> LastLinkQueried;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandLinkScreen")
	TObjectPtr<UFortCreativeIslandLink> UserEnteredIslandLink;

private:
	UFUNCTION()
	void HandleIslandLinkChanged(const FText& Text);

	UFUNCTION()
	void HandleIslandLinkCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	UFUNCTION()
	void HandleIslandSelectionChanged(UObject* Item);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandLinkScreen", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Select;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseMobile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Refresh;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Remove;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandLinkScreen", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Tabs;

	UPROPERTY()
	FCachedIslandsGroup FavoriteIslands;

	UPROPERTY()
	FCachedIslandsGroup IslandHistory;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaCreativePortal> TargetPortal;

	UPROPERTY(Transient)
	FDateTime LastRefreshTime;

	UPROPERTY(Transient)
	FOnlineLinkId LastTestedLinkId;

	UPROPERTY()
	bool bCodeLookupRequestInFlight;

	UPROPERTY()
	bool bFriendsGetRequestInFlight;

	UPROPERTY()
	bool bFavoritesOnlyMode;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandLinkScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DetailsScrollUpInputRowHandle;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandLinkScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DetailsScrollDownInputRowHandle;

};

