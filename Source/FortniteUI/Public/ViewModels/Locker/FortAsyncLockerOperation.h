// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortAsyncLockerOperation.generated.h"

class UFortAsyncAction_LockerOperation;
class UFortItemVM;
class UFortLoadoutVM;
class ULockerConfirmationModal;
class UUserWidget;
enum class EFortLockerAnalyticAction : uint8;

UCLASS(meta=(NotBlueprintType="true"))
class UFortAsyncAction_LockerOperation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOperationCompleted, bool, Success);

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* ArchiveItems(const UUserWidget* ContextWidget, const TArray<UFortItemVM*>& Items, bool bArchiveState);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* CopyLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Source, UFortLoadoutVM* Destination, const FString& OptionalNewName, EFortLockerAnalyticAction AnalyticsAction);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* DeleteLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Loadout);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Variants", BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* EquipItem(const UUserWidget* ContextWidget, const UFortItemVM* Item, int32 SlotIndex, const TArray<FMcpVariantChannelInfo>& Variants, bool bApplyToAllSlots);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* QuickSaveCurrentLoadout(const UUserWidget* ContextWidget);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* RenameLoadout(const UUserWidget* ContextWidget, UFortLoadoutVM* Target, const FString& NewName, EFortLockerAnalyticAction AnalyticsAction);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* ResetToCurrentLoadout(const UUserWidget* ContextWidget);

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="ContextWidget"))
	static UFortAsyncAction_LockerOperation* ShowConfirmationOnEquipIfRequired(const UUserWidget* ContextWidget, const UFortItemVM* Item, TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass);

	UPROPERTY(BlueprintAssignable)
	FOnOperationCompleted OnOperationCompleted;

};

