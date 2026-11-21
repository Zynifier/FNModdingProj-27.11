// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseTemplateDescriptor.generated.h"

USTRUCT()
struct FVerseTemplateReplacement
{
	GENERATED_BODY()

public:
	/** Replacement display title */
	UPROPERTY()
	FString Title;

	/** String to find and replace in the file */
	UPROPERTY()
	FString Token;

};

/**
 * Verse script template descriptor
 */
USTRUCT()
struct FVerseTemplateDescriptor
{
	GENERATED_BODY()

public:
	/** Script template title */
	UPROPERTY()
	FString Title;

	/** Script template description */
	UPROPERTY()
	FString Description;

	/** Whether it's a component script template */
	UPROPERTY()
	bool IsComponent;

	/** Sorting priority in the template list; lower values are listed first */
	UPROPERTY()
	float SortPriority;

	/** List of tokens to replace in the template */
	UPROPERTY()
	TArray<FVerseTemplateReplacement> Replacements;

	/** 
	 * If not empty, a user must have at least one of the specified entitlements in order to use this template
	 * For example: VKCreateUGCEarlyAccess, VKCreateUGCPartner, VKCreateUGCEpicDeveloper
	 * If empty, no entitlements required
	 */
	UPROPERTY()
	TArray<FString> RequiredEntitlements;

};

