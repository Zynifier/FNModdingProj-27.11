// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/Locker/FortAsyncLockerOperation.h"

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::ArchiveItems(const UUserWidget* ContextWidget, const TArray<UFortItemVM*>& Items, bool bArchiveState)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::CopyLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Source, UFortLoadoutVM* Destination, const FString& OptionalNewName, EFortLockerAnalyticAction AnalyticsAction)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::DeleteLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Loadout)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::EquipItem(const UUserWidget* ContextWidget, const UFortItemVM* Item, int32 SlotIndex, const TArray<FMcpVariantChannelInfo>& Variants, bool bApplyToAllSlots)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::QuickSaveCurrentLoadout(const UUserWidget* ContextWidget)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::RenameLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Target, const FString& NewName, EFortLockerAnalyticAction AnalyticsAction)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::ResetToCurrentLoadout(const UUserWidget* ContextWidget)
{
	return nullptr;
}

UFortAsyncAction_LockerOperation* UFortAsyncAction_LockerOperation::ShowConfirmationOnEquipIfRequired(const UUserWidget* ContextWidget, const UFortItemVM* Item, TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass)
{
	return nullptr;
}
