// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SizeBox.h"
#include "Math/MathFwd.h"
#include "FortVisualAttachment.generated.h"

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortVisualAttachment : public USizeBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Child Layout")
	FVector2D ContentAnchor;

};

