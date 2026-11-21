// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortBannerTokenType.generated.h"

UCLASS()
class UFortBannerTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBannerTokenType")
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere, Category="Banner Token")
	FString BannerIconTemplateName;

};

