// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "UObject/NoExportTypes.h"
#include "FabricGridStyle.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fabric UI"))
class UFabricGridStyle : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FMargin Padding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	int32 RowSpan;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	int32 ColumnSpan;

};

