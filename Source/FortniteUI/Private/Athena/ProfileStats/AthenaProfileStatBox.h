// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonNumericTextBlock.h"
#include "Components/SizeBox.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "AthenaProfileStatBox.generated.h"

class UAthenaBaseStatView;

USTRUCT(BlueprintType)
struct FFortUIStatStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIStatStyle")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIStatStyle")
	FText HighestText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIStatStyle")
	FSlateBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIStatStyle")
	ECommonNumericType NumericType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIStatStyle")
	float MinimalNotableValue;

};

UCLASS(Config=FortUI, DefaultConfig, ClassGroup=("UI"), meta=(Category="Fort UI", DisplayName="Athena Profile Stat Box"))
class UAthenaProfileStatBox : public USizeBox
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatViewChanged, UAthenaBaseStatView*, StatView);

public:
	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatBox")
	UAthenaBaseStatView* GetBaseStatView();

	UFUNCTION(BlueprintPure, Category="AthenaProfileStatBox")
	const FFortUIStatStyle& GetStatStyle(const FGameplayTag& InStat) const;

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatBox")
	void SetStatView(UAthenaBaseStatView* InStatView, bool RespectParentStatView = false);

	UPROPERTY(BlueprintAssignable, Category="AthenaProfileStatBox")
	FOnStatViewChanged OnStatViewChanged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaProfileStatBox")
	bool bRespectParentStatView;

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaBaseStatView> StatView;

};

