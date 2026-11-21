// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCharacterPartOwnerInterface.h"

USkeletalMeshComponent* ICustomCharacterPartOwnerInterface::GetCustomizationRootSkeletalMeshComponent() const
{
	return nullptr;
}

void ICustomCharacterPartOwnerInterface::PlayAnimationsMatchingQuery(const FGameplayTagQuery& TagQueryToMatch)
{
}
