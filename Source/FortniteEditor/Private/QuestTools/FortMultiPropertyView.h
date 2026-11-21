// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PropertyViewBase.h"
#include "Math/MathFwd.h"
#include "QuestTools/FortGeneratePropertyPathData.h"
#include "FortMultiPropertyView.generated.h"

UENUM(BlueprintType)
enum class EFortPropertyFilteringMode : uint8
{
	PropertyName = 0,
	PropertyPathAndName = 1,
};

UCLASS()
class UFortMultiPropertyView : public UPropertyViewBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddGeneratePathPropertyNestedIndexData(const FString RootPropertyName, const FString NestedPropertyName, const int32 IndexData);

	UFUNCTION(BlueprintCallable)
	void RebuildPropertyView();

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	TArray<FName> PropertiesToShow;

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	TMap<FName, FIntPoint> PropertyGridLayout;

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	TArray<FName> PropertiesToExclude;

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	bool bShowNameWidgets;

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	bool bShowValueWidgets;

	UPROPERTY(EditAnywhere, Category="FortMultiPropertyView")
	EFortPropertyFilteringMode PropertyFilterMode;

	UPROPERTY(EditAnywhere, Category="Property Path Auto Generation", meta=(EditCondition="PropertyFilterMode == EFortPropertyFilteringMode::PropertyPathAndName"))
	bool bAutoGeneratePropertyPath;

	UPROPERTY(EditAnywhere, Category="Property Path Auto Generation", meta=(EditCondition="PropertyFilterMode == EFortPropertyFilteringMode::PropertyPathAndName && bAutoGeneratePropertyPath"))
	TMap<FString, FFortGeneratePropertyPathData> AutoGeneratePropertyPathData;

};

