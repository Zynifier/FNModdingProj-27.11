// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBrushSize.h"
#include "Item/FortItemWidget_NUI.h"
#include "FortItemCardBase.generated.h"

enum class EFortItemCardSize : uint8;

UCLASS(Abstract, BlueprintType)
class UFortItemCardBase : public UFortItemWidget_NUI
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static EFortItemCardSize PortBrushSize(const TEnumAsByte<EFortBrushSize::Type>& BrushSize);

};

