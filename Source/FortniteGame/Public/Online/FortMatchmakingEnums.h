// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingEnums.generated.h"

UENUM()
enum class EFortSessionHelperJoinResult : uint8
{
	/** Nothing started, mostly an init placeholder */
	NoResult = 0,
	/** Reservation has been made/accepted, expectation is game will clean up and proceed to join */
	ReservationSuccess = 1,
	/** Errors possible from the beacons */
	ReservationFailure_PartyLimitReached = 2,
	ReservationFailure_IncorrectPlayerCount = 3,
	ReservationFailure_RequestTimedOut = 4,
	ReservationFailure_ReservationNotFound = 5,
	ReservationFailure_ReservationDenied = 6,
	ReservationFailure_ReservationDenied_Banned = 7,
	ReservationFailure_ReservationRequestCanceled = 8,
	ReservationFailure_ReservationInvalid = 9,
	ReservationFailure_BadSessionId = 10,
	ReservationFailure_ReservationDenied_ContainsExistingPlayers = 11,
	ReservationFailure_GeneralError = 12,
	/** Local reservation errors */
	ReservationFailure_NoSubsystem = 13,
	ReservationFailure_NoIdentity = 14,
	ReservationFailure_InvalidSession = 15,
	ReservationFailure_InvalidUser = 16,
	ReservationFailure_EncryptionKey = 17,
	ReservationFailure_RefreshAuth = 18,
	ReservationFailure_AlreadyJoiningDuringReserve = 19,
	ReservationFailure_AlreadyJoiningDuringSkip = 20,
	/** Joining the session has succeeded, expectation is game will actually travel to the session */
	JoinSessionSuccess = 21,
	/** Errors possible from the session interface */
	JoinSessionFailure_SessionIsFull = 22,
	JoinSessionFailure_SessionDoesNotExist = 23,
	JoinSessionFailure_CouldNotRetrieveAddress = 24,
	JoinSessionFailure_AlreadyInSession = 25,
	JoinSessionFailure_UnknownError = 26,
	/** Local join errors */
	JoinSessionFailure_InvalidSession = 27,
	JoinSessionFailure_InvalidSearchResultIndex = 28,
	JoinSessionFailure_AlreadyJoiningDuringJoin = 29,
	SearchPassFailure_NoSessionHelper = 30,
	SearchPassFailure_InvalidUser = 31,
	SearchPassFailure_NoIdentity = 32,
	SearchPassFailure_InvalidSearchResult = 33,
	SearchPassFailure_InvalidSearchResultIndex = 34,
	/** Join request was canceled */
	JoinSessionCanceled = 35,
};

