// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CustomCharacterPartOwnerInterface.generated.h"

class USkeletalMeshComponent;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UCustomCharacterPartOwnerInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ICustomCharacterPartOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual USkeletalMeshComponent* GetCustomizationRootSkeletalMeshComponent() const;

	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual void PlayAnimationsMatchingQuery(const FGameplayTagQuery& TagQueryToMatch);

};

