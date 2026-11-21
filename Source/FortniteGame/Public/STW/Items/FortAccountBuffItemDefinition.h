// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortAccountBuffItemDefinition.generated.h"

class UGameplayEffect;

UCLASS(BlueprintType)
class UFortAccountBuffItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAccountBuffItemDefinition")
	TArray<TSoftClassPtr<UGameplayEffect>> BuffEffects;

};

