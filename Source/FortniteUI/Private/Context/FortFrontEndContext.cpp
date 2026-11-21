// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortFrontEndContext.h"

void UFortFrontEndContext::AccountItemWarningShown()
{
}

bool UFortFrontEndContext::AreProfilesAvailableForWriting() const
{
	return false;
}

void UFortFrontEndContext::BroadcastMainTabSelected(FName TabName)
{
}

bool UFortFrontEndContext::CanCompleteQuestInFocusedOrActiveTileMission(UFortQuestItem* QuestItem) const
{
	return false;
}

bool UFortFrontEndContext::CanFindTileForQuest(UFortQuestItem* QuestItem)
{
	return false;
}

bool UFortFrontEndContext::CanShowLockerSlotType(EAthenaCustomizationCategory SlotType) const
{
	return false;
}

void UFortFrontEndContext::ClearLocalPreview(bool StopUsingLocalPreview)
{
}

void UFortFrontEndContext::ClearSelectedTheater()
{
}

void UFortFrontEndContext::GetAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 AccountLevel) const
{
}

AFortTheaterMapTile* UFortFrontEndContext::GetActiveTile() const
{
	return nullptr;
}

bool UFortFrontEndContext::GetActiveTileMissionDetails(FFortMissionDetails& MissionDetails) const
{
	return false;
}

bool UFortFrontEndContext::GetAllTheaterData(TArray<FFortTheaterMapData>& OutAllTheaterData) const
{
	return false;
}

TArray<FGameDifficultyInfo> UFortFrontEndContext::GetAvailableDifficulties(bool bIncludeMissionAlertTiles) const
{
	return TArray<FGameDifficultyInfo>();
}

void UFortFrontEndContext::GetCriticalMissionRewards(TArray<FFortMissionRewardInfo>& RewardList) const
{
}

int32 UFortFrontEndContext::GetCurrentLockerSubslotIndex()
{
	return int32();
}

FText UFortFrontEndContext::GetCurrentTheaterName() const
{
	return FText();
}

void UFortFrontEndContext::GetFeatureState(const EFortFrontEndFeature Feature, EFortFrontEndFeatureState& OutFeatureState, EFortFrontEndFeatureStateReason& OutReason) const
{
}

AFortTheaterMapTile* UFortFrontEndContext::GetFocusedOrActiveTile() const
{
	return nullptr;
}

bool UFortFrontEndContext::GetFocusedOrActiveTileMissionDetails(FFortMissionDetails& MissionDetails) const
{
	return false;
}

EFrontEndCamera UFortFrontEndContext::GetFrontEndCamera() const
{
	return EFrontEndCamera();
}

AFortPlayerPawn* UFortFrontEndContext::GetHeroPlayerPawnByIndex(int32 PartyMemberIndex)
{
	return nullptr;
}

AFortPlayerPawn* UFortFrontEndContext::GetHeroPlayerPawnForCurrentDisplayedItem()
{
	return nullptr;
}

bool UFortFrontEndContext::GetHighestEnduranceWaveReachedByItemDefinition(UFortOutpostItemDefinition* OutpostCoreItemDef, int32& HighestWaveNumber) const
{
	return false;
}

EFortFrontendInventoryFilter UFortFrontEndContext::GetInventoryFilterForAccountItemWarning() const
{
	return EFortFrontendInventoryFilter();
}

UFortItemDefinition* UFortFrontEndContext::GetItemFromItemQuantityPair(const FFortItemQuantityPair& InPair) const
{
	return nullptr;
}

FGameDifficultyInfo UFortFrontEndContext::GetMaxAvailableDifficulty(bool bIncludeMissionAlertTiles) const
{
	return FGameDifficultyInfo();
}

FText UFortFrontEndContext::GetMCPRegion() const
{
	return FText();
}

FText UFortFrontEndContext::GetMCPRegionText() const
{
	return FText();
}

bool UFortFrontEndContext::GetOutpostCoreLevelByItemDefinition(UFortOutpostItemDefinition* OutpostCoreItemDef, int32& OutCoreLevel) const
{
	return false;
}

bool UFortFrontEndContext::GetOutpostCoreLevelByTheaterId(const FString& TheaterId, int32& OutCoreLevel) const
{
	return false;
}

void UFortFrontEndContext::GetPostMaxAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 RewardOffset) const
{
}

FUnlockableVariantPreviewInfo UFortFrontEndContext::GetSeasonTabVariantPreviewInfo()
{
	return FUnlockableVariantPreviewInfo();
}

void UFortFrontEndContext::GetSelectableGadgets(TArray<UFortWorldItem*>& SelectableGadgets, TArray<UFortWorldItem*>& LastSelectedGadgets)
{
}

bool UFortFrontEndContext::GetSelectedTheaterData(FFortTheaterMapData& OutTheaterData) const
{
	return false;
}

FString UFortFrontEndContext::GetSelectedTheaterId() const
{
	return FString();
}

bool UFortFrontEndContext::GetTheaterData(const FString& TheaterId, FFortTheaterMapData& OutTheaterData) const
{
	return false;
}

bool UFortFrontEndContext::GetTileMissionDetails(const AFortTheaterMapTile* Tile, FFortMissionDetails& MissionDetails) const
{
	return false;
}

bool UFortFrontEndContext::GetUIOrderedAllTheaterData(TArray<FFortTheaterMapData>& OutAllTheaterData) const
{
	return false;
}

UClass* UFortFrontEndContext::GetUITestingClass() const
{
	return nullptr;
}

void UFortFrontEndContext::HandleDynamicSocialImportClosed()
{
}

void UFortFrontEndContext::HideAthenaStoreNewItemBang() const
{
}

bool UFortFrontEndContext::Is4PlayerTile(const AFortTheaterMapTile* Tile) const
{
	return false;
}

bool UFortFrontEndContext::IsActiveTileMissionValid()
{
	return false;
}

bool UFortFrontEndContext::IsCelebrateEffectPlaying()
{
	return false;
}

bool UFortFrontEndContext::IsTileMissionAlertRewardClaimed(const AFortTheaterMapTile* Tile) const
{
	return false;
}

void UFortFrontEndContext::OnPlayerProfileInitialized()
{
}

void UFortFrontEndContext::PlayEvolutionEffect()
{
}

void UFortFrontEndContext::PlayLevelUpEffect()
{
}

void UFortFrontEndContext::PushContentWidget_Adv(UWidget* Widget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortFrontEndContext::SelectDefaultTheater()
{
}

void UFortFrontEndContext::SelectDefaultTheaterTile()
{
}

bool UFortFrontEndContext::SelectTileForQuest(UFortQuestItem* QuestItem, float& OutCriticalMissionDifficultyOverrideMin, float& OutCriticalMissionDifficultyOverrideMax)
{
	return false;
}

void UFortFrontEndContext::SetCurrentLockerSubslotIndex(int32 NewIndex)
{
}

void UFortFrontEndContext::SetDefaultLocalVariantPreview(const UAthenaCosmeticItemDefinition* CosmeticItem)
{
}

void UFortFrontEndContext::SetFrontEndCamera(EFrontEndCamera NewState, FViewTargetTransitionParams TransitionParams)
{
}

void UFortFrontEndContext::SetFrontEndVisibility(bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortFrontEndContext::SetLocalVariantPreview(const UAthenaCosmeticItemDefinition* CosmeticItem, FGameplayTag VariantChannelTag, FGameplayTag VariantTag, const FString& CustomData)
{
}

void UFortFrontEndContext::SetSeasonTabVariantPreviewInfo(FUnlockableVariantPreviewInfo Info)
{
}

void UFortFrontEndContext::SetSelectedTheater(const FString& TheaterId)
{
}

bool UFortFrontEndContext::ShouldShowAccountItemWarning() const
{
	return false;
}

bool UFortFrontEndContext::ShouldShowPhoenixDisplay() const
{
	return false;
}

bool UFortFrontEndContext::ShouldShowSocialImport() const
{
	return false;
}

UFortSocialImportPanel* UFortFrontEndContext::ShowSocialImport(TSubclassOf<UFortSocialImportPanel> PanelClass)
{
	return nullptr;
}

void UFortFrontEndContext::ViewVaultItem(const UFortItem* ItemToView, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext)
{
}

void UFortFrontEndContext::ViewVaultItemFromDefinition(const UFortItemDefinition* ItemToViewDefinition, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext)
{
}

void UFortFrontEndContext::ViewVaultItems(const TArray<UFortItem*>& ItemsToView, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext)
{
}

void UFortFrontEndContext::ViewVaultItemsFromOffer(const FCatalogOffer& CatalogOffer, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext)
{
}
