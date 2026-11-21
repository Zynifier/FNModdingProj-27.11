// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Feature/FortUIFeature.h"
#include "FortStandaloneFrontend.h"
#include "FortStandaloneItemShop.generated.h"

class UAthenaItemShopScreen;
class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UDynamicEntryBox;
class UFortMPItemShopScreen;
class UFortMtxStoreRootBase;
class UObject;

USTRUCT(BlueprintType)
struct FStandaloneItemShopTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StandaloneItemShopTabInfo")
	FText TabTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StandaloneItemShopTabInfo")
	FName TabNameId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StandaloneItemShopTabInfo", meta=(AllowedClasses="/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", DisallowedClasses="/Script/MediaAssets.MediaTexture", DisplayName="Image", DisplayThumbnail="true"))
	TObjectPtr<UObject> TabIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="StandaloneItemShopTabInfo", meta=(EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> TabWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StandaloneItemShopTabInfo")
	EFortUIFeature UIFeature;

};

UCLASS()
class UFortStandaloneItemShop : public UFortStandaloneFrontend
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CreateTabs();

	UFUNCTION()
	void HandleSelectedTabButtonChanged(UCommonButtonBase* SelectedButton, int32 ButtonIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeTabs();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabSelected(int32 TabIndex);

	UFUNCTION(BlueprintCallable)
	void RegisterTab(const FStandaloneItemShopTabInfo& TabInfo);

	UFUNCTION(BlueprintCallable)
	void SelectButtonAtIndex(int32 ButtonIndex);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneItemShop", meta=(BindWidget, EditInline="true", EntryClass="CommonButtonBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_TabButtons;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortStandaloneItemShop", meta=(AllowPrivateAccess="TRUE", RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortStandaloneItemShop", meta=(AllowPrivateAccess="TRUE", RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> TabsGroup;

	UPROPERTY(Transient)
	TArray<FStandaloneItemShopTabInfo> TabInfos;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneItemShop", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopScreen> ActivatableContent_ItemShop;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneItemShop", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortMtxStoreRootBase> ActivatableContent_MtxStore;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStandaloneItemShop", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortMPItemShopScreen> ActivatableContent_MPItemShop;

};

