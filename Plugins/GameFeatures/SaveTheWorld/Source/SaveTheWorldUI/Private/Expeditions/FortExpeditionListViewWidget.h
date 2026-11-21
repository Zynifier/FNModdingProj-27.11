// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortExpeditionListViewWidget.generated.h"

class UCommonListView;
class UFortExpeditionItem;
enum class EFortExpeditionListSort : uint8;

UENUM(BlueprintType)
enum class EFortExpeditionListSort : uint8
{
	ByRating = 0,
	ByDuration = 1,
	ByName = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExpeditionListItemSelected, UFortExpeditionItem*, Item);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExpeditionListViewRefreshed);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionListViewWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Expedition")
	FText GetExpeditionListSortName() const;

	UFUNCTION(BlueprintCallable, Category="Expedition")
	void SetExpeditionListSortType(EFortExpeditionListSort InSortType);

	UPROPERTY(BlueprintAssignable, Category="Expedition|Events")
	FOnExpeditionListItemSelected OnExpeditionSelected;

	UPROPERTY(BlueprintAssignable, Category="Expedition|Events")
	FOnExpeditionListViewRefreshed OnExpeditionListViewRefreshed;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition|Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ExpeditionListView;

	UPROPERTY(Transient)
	FName CurrentTabNameId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Expedition")
	EFortExpeditionListSort SortType;

};

