// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "AthenaChallengeImageGridEntry.generated.h"

class UCommonLazyImage;
class UFortChallengeBundleItemDefinition;
class UFortQuestItem;

USTRUCT()
struct FGlyphAllUpdateTransitions
{
	GENERATED_BODY()

};

USTRUCT()
struct FGlyphUpdateTransition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Count;

	UPROPERTY()
	float MinTimeOffset;

	UPROPERTY()
	float MaxTimeOffset;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeImageGridEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeSet(bool bIsComplete, bool bIsLocked);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupLockedToOwnState();

	UFUNCTION(BlueprintImplementableEvent)
	void TransitionFromLockedToOwnedState();

	UFUNCTION(BlueprintImplementableEvent)
	void TransitionFromOwnedToCompletedState();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaChallengeImageGridEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Brush;

	UPROPERTY(Transient)
	bool bSelected;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeImageGridEntry", meta=(AllowPrivateAccess="TRUE", BlueprintProtected="TRUE"))
	int32 GridLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeImageGridEntry", meta=(AllowPrivateAccess="TRUE", BlueprintProtected="TRUE"))
	int32 Column;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengeImageGridEntry", meta=(AllowPrivateAccess="TRUE", BlueprintProtected="TRUE"))
	int32 Row;

};

UCLASS()
class UImageGridObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 GridLocation;

	UPROPERTY()
	TObjectPtr<UFortChallengeBundleItemDefinition> BundleData;

	UPROPERTY()
	TObjectPtr<UFortQuestItem> QuestItem;

};

