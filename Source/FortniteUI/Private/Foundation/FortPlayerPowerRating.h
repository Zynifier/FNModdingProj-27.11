// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortPlayerPowerRating.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EFortPlayerPowerRatingType : uint8
{
	// Phoenix if in a Phoenix zone or the selected theater is a Phoenix theater, Campaign otherwise.

	Auto = 0,
	Campaign = 1,
	Phoenix = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerPowerRating : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPowerRatingUpdated);

public:
	UFUNCTION(BlueprintPure)
	bool HasTeamMembers() const;

	UFUNCTION(BlueprintCallable)
	void RepresentLocalPlayer();

	UPROPERTY(BlueprintAssignable)
	FOnPowerRatingUpdated OnPowerRatingUpdated;

protected:
	UFUNCTION(BlueprintPure)
	int32 GetBasePowerRating() const;

	UFUNCTION(BlueprintPure)
	int32 GetTeamPowerRating() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBasePowerRatingUpdated(int32 BasePowerRating);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPowerRatingProgressUpdated(float BaseRatingProgress, float TeamRatingProgress);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamMembershipChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamPowerRatingUpdated(int32 TeamPowerRating);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPlayerPowerRating")
	EFortPlayerPowerRatingType PowerRatingType;

};

