// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativePropertySubcategoryHeaderListItem.generated.h"

class UObject;

UCLASS(BlueprintType, Blueprintable)
class UFortCreativePropertySubcategoryHeaderListItem : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsExpandedChangedDynamic, const bool, bIsExpanded);

public:
	UFUNCTION(BlueprintPure)
	const FGameplayTag& GetSubcategoryTag() const;

	UFUNCTION(BlueprintPure)
	bool IsExpanded() const;

	UFUNCTION(BlueprintCallable)
	void SetIsExpanded(const bool bInIsExpanded);

protected:
	UPROPERTY(BlueprintAssignable, meta=(DisplayName="OnIsExpandedChanged"))
	FOnIsExpandedChangedDynamic OnIsExpandedChangedDynamicDelegate;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> Options;

};

