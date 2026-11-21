// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMatchmakingKnobsModal.h"

void UFortMatchmakingKnobsModal::ApplyChanges(const bool bApplySettingsFromCachedData, const bool bApplyAllOptions)
{
}

TScriptInterface<IFortActorLabelOverrideInterface> UFortMatchmakingKnobsModal::BP_GetLabelOverrideInterface() const
{
	return TScriptInterface<IFortActorLabelOverrideInterface>();
}

UFortActorOptionsComponent* UFortMatchmakingKnobsModal::BP_GetOptionsComponent() const
{
	return nullptr;
}

TScriptInterface<IUserOptionValuesInterface> UFortMatchmakingKnobsModal::BP_GetUserOptionValuesInterface() const
{
	return TScriptInterface<IUserOptionValuesInterface>();
}

bool UFortMatchmakingKnobsModal::DoesContainString(const UObject* Option, const FString& String)
{
	return false;
}

EFortModifiedStatus UFortMatchmakingKnobsModal::GetModificationStatus(const UObject* Option) const
{
	return EFortModifiedStatus();
}

TArray<FString> UFortMatchmakingKnobsModal::GetScrolledOffWhitelistedPlayers()
{
	return TArray<FString>();
}

FString UFortMatchmakingKnobsModal::GetSearchString() const
{
	return FString();
}

void UFortMatchmakingKnobsModal::GetSearchStringFilteredOptionCategoryTags(FGameplayTagContainer& OutSearchStringFilteredOptionCategoryTags)
{
}

EFortModifiedStatus UFortMatchmakingKnobsModal::GetSpinnerModificationStatus(const UFortMatchmakingKnobsSpinnerButton* SpinnerButton) const
{
	return EFortModifiedStatus();
}

void UFortMatchmakingKnobsModal::HandleCancelClicked_Implementation()
{
}

void UFortMatchmakingKnobsModal::HandleForcedOffIsland()
{
}

void UFortMatchmakingKnobsModal::HandleLeaveIsland(AFortPlayerPawn* PlayerPawn)
{
}

void UFortMatchmakingKnobsModal::HandleRestoreEventsClicked()
{
}

void UFortMatchmakingKnobsModal::HandleRestoreFunctionsClicked()
{
}

void UFortMatchmakingKnobsModal::HandleRestorePropertiesClicked()
{
}

bool UFortMatchmakingKnobsModal::HasEventDescriptorProperty() const
{
	return false;
}

bool UFortMatchmakingKnobsModal::HasEventFunctionProperty() const
{
	return false;
}

bool UFortMatchmakingKnobsModal::HasMatchingTags(const UObject* Option, const FGameplayTagContainer& CategoryTags, const FGameplayTagContainer& ContextTags)
{
	return false;
}

bool UFortMatchmakingKnobsModal::HasNonEventProperties() const
{
	return false;
}

void UFortMatchmakingKnobsModal::InitForToyOptionsActor(AActor* InActor)
{
}

void UFortMatchmakingKnobsModal::InitializeData()
{
}

void UFortMatchmakingKnobsModal::OnAcceptAnimationComplete(const bool bApplyAllOptions)
{
}

void UFortMatchmakingKnobsModal::OnCurrentItemSelectionChanged(UObject* Item)
{
}

void UFortMatchmakingKnobsModal::OnHoveredItemChanged(UObject* Item, bool bIsHovered)
{
}

void UFortMatchmakingKnobsModal::RestoreOptionsToDefault(const bool bRestoreAllOptions)
{
}

void UFortMatchmakingKnobsModal::SetListDataSource(UFortMatchmakingKnobsDataSource::Type ListType)
{
}

void UFortMatchmakingKnobsModal::SetOptionCategoryTagFilter(const FGameplayTagContainer& InOptionCategoryTagFilter)
{
}

void UFortMatchmakingKnobsModal::SetSearchString(const FString& InSearchString)
{
}
