// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CollectionNPCServiceContainer.generated.h"

class UCollectionScreenServiceVisualData;
class UDataTable;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCollectionNPCServiceContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	UCollectionNPCServiceContainer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="PopulateServiceData"))
	void BP_PopulateServiceData(const bool bShowProgress, const int32 CurrentBenefitsLvl, const int32 TotalBenefitsLvl);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CollectionNPCServiceGroup"))
	UDynamicEntryBox* EntryBox_ServiceGroups;

	UPROPERTY(EditAnywhere, Category="CollectionNPCServiceContainer", meta=(ClampMin="1"))
	int32 MaxGroupSize;

	UPROPERTY(EditAnywhere, Category="CollectionNPCServiceContainer")
	bool bExcludeAlwaysAvailableServices;

	UPROPERTY(EditAnywhere, Category="CollectionNPCServiceContainer")
	bool bShowLinesBetweenServices;

	UPROPERTY(EditDefaultsOnly, Category="CollectionNPCServiceContainer")
	TObjectPtr<UCollectionScreenServiceVisualData> SharedServiceVisualData;

	UPROPERTY(Transient)
	TArray<UDataTable*> GameFeatureLootTierData;

	UPROPERTY(Transient)
	TArray<UDataTable*> GameFeatureLootPackageData;

};

