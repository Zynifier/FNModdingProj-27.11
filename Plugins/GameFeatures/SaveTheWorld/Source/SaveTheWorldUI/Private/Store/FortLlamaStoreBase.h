// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "DirectedAcquisition/FortDirectAcquisitionWidgetBase.h"
#include "FortLlamaStoreBase.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UDynamicEntryBox;
class UFortLlamaStoreData;
class UFortLlamaStoreDetailsBase;
class UFortLlamaStoreOfferInfo;
class UFortOpenCardPackModal;
class UFortOpenCardPackModal_Legacy;
class UFortStoreFrontOfferDetailsWidgetBase;
enum class EFortStoreState : uint8;

USTRUCT(BlueprintType)
struct FOfferGroup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OfferGroup")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OfferGroup")
	int32 MaxNumberToShow;

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"))
class UFortLlamaStoreBase : public UFortDirectAcquisitionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreBase")
	void CreateTencentPuchaseOpenModal();

	UFUNCTION(BlueprintImplementableEvent, Category="Input", meta=(BlueprintProtected="true"))
	void HandleAddVBucks();

	UFUNCTION(BlueprintImplementableEvent, Category="Input", meta=(BlueprintProtected="true"))
	void HandleTencentDetails();

	UFUNCTION()
	void OnStoreStateChanged(EFortStoreState NewStoreState);

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreBase")
	void SetupFocus();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreBase")
	void SwapToCardEnterState();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreBase")
	TArray<FOfferGroup> OfferCategoriesToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle TencentDetailsActionData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle AddVBucksActionData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	bool bShouldShowAddVBucksAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreBase", meta=(BindWidget, EditInline="true"))
	UDynamicEntryBox* OfferEntryBox;

	UPROPERTY()
	UCommonButtonGroupBase* OfferButtonGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreBase", meta=(BindWidgetOptional, EditInline="true"))
	UFortLlamaStoreDetailsBase* OfferDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreBase")
	TObjectPtr<UFortLlamaStoreData> StoreData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortllamaStoreBase", meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_UnopenedLlamas;

private:
	UFUNCTION()
	void OnStorePurchaseCompleted();

	UPROPERTY()
	UFortLlamaStoreOfferInfo* PendingPurchaseOffer;

	UPROPERTY(Export, meta=(EditInline="true"))
	UCommonActivatablePanelLegacy* StoreOpeningCardPack;

	UPROPERTY(EditAnywhere, Category="FortllamaStoreBase", meta=(AllowPrivateAccess="true"))
	bool bHideSoldOffers;

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortLlamaStoreData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	TArray<FText> RandomLoadingTexts;

	UPROPERTY(EditAnywhere, Category="FortLlamaStoreData")
	FName NotEnoughCurrencyDialogCloseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	TSubclassOf<UFortStoreFrontOfferDetailsWidgetBase> InspectWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	float ShowOfferDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	TSubclassOf<UCommonActivatablePanelLegacy> StoreOpeningCardPackClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	TSubclassOf<UFortOpenCardPackModal> UnopenedCardpacksModalClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreData")
	TSubclassOf<UFortOpenCardPackModal_Legacy> UnopenedCardpacksModalClass_Legacy;

};

