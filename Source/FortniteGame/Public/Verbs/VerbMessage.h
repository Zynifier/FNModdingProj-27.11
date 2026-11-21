// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "VerbMessage.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSubjectTagsPair
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SubjectTagsPair", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UObject> Subject;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SubjectTagsPair", meta=(AllowPrivateAccess))
	FGameplayTagContainer Tags;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FVerbMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage")
	FGameplayTagContainer ContextTags;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage", meta=(AllowPrivateAccess))
	FSubjectTagsPair Author;

};

