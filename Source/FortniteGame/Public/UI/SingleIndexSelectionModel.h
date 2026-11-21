// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SingleIndexSelectionModel.generated.h"

class UObject;
enum class EIndexNavigationResult : uint8;

UENUM(BlueprintType)
enum class EIndexNavigationResult : uint8
{
	/** The requested movement was carried out */
	Succeeded = 0,
	/** The requested movement was partially carried out but may have been altered */
	Modified = 1,
	/** The requested movement was not carried out due to clamping */
	Clamped = 2,
	/**
	 * The requested movement was not carried out due to stepping off the end of
	 * the navigable range. This differs from "Clamped" in that it is effectively
	 * saying "this movement would be allowed, except that there are no more items
	 * within this range." If the navigable range is part of a larger sequence,
	 * this is a signal that navigation can be moved beyond the range represented
	 * by the model.
	 */
	StepOff = 3,
	/** No movement was attempted */
	NoMove = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FIndexSelectionModelChangedDelegate, UObject*, Source);

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class USingleIndexSelectionModel : public UInterface
{
	GENERATED_BODY()
};

class ISingleIndexSelectionModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void AddOnNavigationChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void AddOnNumItemsChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void AddOnSelectedIndexChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, Category="Index Selection Model")
	virtual EIndexNavigationResult CanMoveDelta(int32 InDelta) const;

	UFUNCTION(BlueprintCallable, Category="Index Selection Model")
	virtual int32 GetNumItems() const;

	UFUNCTION(BlueprintCallable, Category="Index Selection Model")
	virtual int32 GetSelectedIndex() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void RemoveOnNavigationChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void RemoveOnNumItemsChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Index Selection Model")
	virtual void RemoveOnSelectedIndexChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const;

	UFUNCTION(BlueprintCallable, Category="Index Selection Model")
	virtual void SetSelectedIndex(int32 Value);

	UFUNCTION(BlueprintCallable, Category="Index Selection Model")
	virtual EIndexNavigationResult TryMoveDelta(int32 InDelta);

};

