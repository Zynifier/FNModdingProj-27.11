// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "FortSZAwareImage.generated.h"

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortSZAwareImage : public UImage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSZAwareImage")
	bool AnchorLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSZAwareImage")
	bool AnchorRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSZAwareImage")
	bool AnchorTop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSZAwareImage")
	bool AnchorBottom;

};

