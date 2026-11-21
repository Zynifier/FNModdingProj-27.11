// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "AthenaScrollBox.generated.h"

UCLASS()
class UAthenaScrollBox : public UScrollBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scroll")
	bool bEnableFixedPageOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scroll")
	bool bEnableClickThrough;

};

