// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "CustomPropertyViewData.generated.h"

USTRUCT(BlueprintType)
struct FPropertyBorderStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyBorderStyle")
	FName BackgroundImageName;

	UPROPERTY(EditAnywhere, Category="PropertyBorderStyle")
	FLinearColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category="PropertyBorderStyle")
	FMargin Padding;

};

USTRUCT()
struct FPropertyGroupData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyGroupData")
	FName GroupName;

	UPROPERTY(EditAnywhere, Category="PropertyGroupData")
	FLinearColor GroupColor;

};

USTRUCT(BlueprintType)
struct FPropertyToShowData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyToShowData")
	FName PropertyName;

	UPROPERTY(EditAnywhere, Category="PropertyToShowData")
	FText PropertyNameOverride;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowChildren;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowPropertiesOfSameName;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowContainerProperty;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bForceShowProperty;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bForceShowParentProperty;

	UPROPERTY(EditAnywhere, Category="Name")
	bool bShowName;

	UPROPERTY(EditAnywhere, Category="Value")
	bool bShowValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Visibility", meta=(ClampMin="1", UIMin="1"))
	int32 ColumnNumber;

};

USTRUCT()
struct FPropertyViewColumnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropertyViewColumnData")
	int32 ColumnWidth;

	UPROPERTY(EditAnywhere, Category="PropertyViewColumnData")
	float NameFillWidth;

	UPROPERTY(EditAnywhere, Category="PropertyViewColumnData")
	float ValueFillWidth;

};

