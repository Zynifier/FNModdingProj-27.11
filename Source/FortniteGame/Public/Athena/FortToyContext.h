// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "BlueprintContextBase.h"
#include "FortToyContext.generated.h"

class AFortPlayerState;
enum class EMessageFeedRelationshipFilter : uint8;
enum class EMessageFeedSubject : uint8;

UENUM(BlueprintType)
enum class EMessageFeedRelationshipFilter : uint8
{
	Anyone = 0,
	SquadAndTeamMembers = 1,
	SquadMembersOnly = 2,
	SelfOnly = 3,
};

UENUM(BlueprintType)
enum class EMessageFeedSubject : uint8
{
	ToyOwner = 0,
	OtherPlayerInteractingWithToy = 1,
};

UCLASS(Config=Game)
class UFortToyContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool ConditionalPrintToMessageFeed(AFortPlayerState* Instigator, FVector MessageLocation, EMessageFeedRelationshipFilter RelationshipFilter, const FText& Message);

	UFUNCTION(BlueprintCallable)
	FText FormatPlayerNameForDisplay(AFortPlayerState* Subject, EMessageFeedSubject SubjectType);

	UFUNCTION(BlueprintCallable)
	FString GetFilteredPlayerName(AFortPlayerState* Instigator);

	UFUNCTION(BlueprintCallable)
	FText PickToyOwnerNameStyle(AFortPlayerState* Instigator);

	UFUNCTION(BlueprintCallable)
	void PrintToMessageFeed(const FText& Message);

};

