// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataAsset.h"
#include "FortCreativeIslandSelectV2.generated.h"

class UFortCreativeIslandSelectScreen;
class UFortCreativeIslandSelectTab;
class UFortCreativeIslandSelectTabData;
class UFortGameActivityProvider;

UENUM(BlueprintType)
enum class EFortCreativeIslandSelectTabType : uint8
{
	IslandCode = 0,
	ListView = 1,
};

UCLASS(BlueprintType)
class UFortCreativeIslandSelectTabData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData")
	EFortCreativeIslandSelectTabType TabType;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData")
	FText Title;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData", meta=(MultiLine="TRUE"))
	FText EmptyTabDescription;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData")
	int32 IndexOverride;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData")
	TSubclassOf<UFortCreativeIslandSelectTab> WidgetClass;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectTabData")
	TSubclassOf<UFortGameActivityProvider> DataProvider;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelectV2 : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Data")
	TArray<TObjectPtr<UFortCreativeIslandSelectTabData>> TabData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandSelectV2", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeIslandSelectScreen> IslandSelect_Base;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCreativeIslandSelectTab>> Tabs;

};

