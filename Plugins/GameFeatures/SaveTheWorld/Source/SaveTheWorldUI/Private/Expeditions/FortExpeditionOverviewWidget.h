// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTabListWidgetBase.h"
#include "FortExpeditionOverviewWidget.generated.h"

class UCommonButtonBase;
class UFortExpeditionListViewWidget;
class UFortTabListWidgetBase_Legacy;

USTRUCT(BlueprintType)
struct FExpeditionTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExpeditionTabInfo")
	FName TabNameId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExpeditionTabInfo")
	FFortTabButtonLabelInfo TabLabelInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionOverviewWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnExpeditionOverviewRefresh();

	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnExpeditionTabSelected(const FName& TabNameId);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	void UpdateExpeditionTabs();

	UPROPERTY(EditAnywhere, Category="Expedition")
	TSubclassOf<UCommonButtonBase> TabButtonType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Expedition")
	TArray<FExpeditionTabInfo> TabListRegistrationInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition|Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> ExpeditionTabList;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition|Widget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortExpeditionListViewWidget> ExpeditionListView;

private:
	UFUNCTION()
	void HandleExpeditionTabButtonCreated(FName TabNameId, UCommonButtonBase* TabButton);

	UFUNCTION()
	void HandleExpeditionTabSelected(FName TabNameId);

};

