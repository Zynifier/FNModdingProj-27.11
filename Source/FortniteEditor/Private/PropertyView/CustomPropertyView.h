// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PropertyViewBase.h"
#include "Layout/Margin.h"
#include "PropertyView/CustomPropertyViewData.h"
#include "CustomPropertyView.generated.h"

UCLASS()
class UCustomPropertyView : public UPropertyViewBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FPropertyViewColumnData> Columns;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool bShowAllProperties;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool bParentPropertiesStartCollapsed;

	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FPropertyToShowData> PropertiesToShow;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool bShowPropertiesThatMatchGeneratedPropertyPaths;

	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FName> PropertiesToExclude;

	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FName> PropertiesToSkipPropertyPathGeneration;

	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FPropertyGroupData> PropertyGroups;

	UPROPERTY(EditAnywhere, Category="Style")
	FPropertyBorderStyle OuterBorderStyle;

	UPROPERTY(EditAnywhere, Category="Style")
	FPropertyBorderStyle ParentBorderStyle;

	UPROPERTY(EditAnywhere, Category="Style")
	FPropertyBorderStyle ChildBorderStyle;

	UPROPERTY(EditAnywhere, Category="Style")
	FMargin NamePadding;

	UPROPERTY(EditAnywhere, Category="Style")
	FMargin ValuePadding;

};

