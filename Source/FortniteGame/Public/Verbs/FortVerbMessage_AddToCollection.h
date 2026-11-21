// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_AddToCollection.generated.h"

USTRUCT()
struct FFortVerbMessage_AddToCollection : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToCollection")
	FSubjectTagsPair ItemDiscovered;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToCollection")
	FGameplayTag CollectionType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AddToCollection")
	bool bIsNewlyFound;

};

