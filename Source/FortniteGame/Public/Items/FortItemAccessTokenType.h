// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortItemAccessTokenType.generated.h"

class UFortItemDefinition;

UCLASS(MinimalAPI)
class UFortItemAccessTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Access Token")
	UFortItemDefinition* GetAccessItem() const;

	UFUNCTION(BlueprintPure, Category="Item Access Token")
	const FText& GetUnlockDescription() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemAccessTokenType")
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere, Category="Item Access Token")
	TObjectPtr<UFortItemDefinition> access_item;

	UPROPERTY(EditDefaultsOnly, Category="Item Access Token", meta=(MultiLine="true"))
	FText UnlockDescription;

};

